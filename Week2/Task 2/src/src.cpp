#include <sstream>
#include <exception>
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u,
    const string& hint)
{
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u
            << " hint: " << hint;
        throw runtime_error(os.str());
    }
}

inline void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        }
        catch (runtime_error& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

void TestNoRoots()
{
    AssertEqual(GetDistinctRealRootCount(1, 0, 1), 0, "x^2+1=0 0 roots");
    AssertEqual(GetDistinctRealRootCount(0, 0, 5), 0, "5=0 0 roots");
    AssertEqual(GetDistinctRealRootCount(10, 2, 1), 0, "10x^2+2x+1=0 0 roots");
    AssertEqual(GetDistinctRealRootCount(0, 0, -1), 0, "-1=0 0 roots");
    AssertEqual(GetDistinctRealRootCount(0, 0, 10000000), 0, "x^2+1=0 0 roots");
}

void TestOneRoot()
{
    AssertEqual(GetDistinctRealRootCount(0, 2, 1), 1, "2x+1=0 1 roots");
    AssertEqual(GetDistinctRealRootCount(1, 0, 0), 1, "x^2=0 1 roots");
    AssertEqual(GetDistinctRealRootCount(0, -100, 1), 1, "-100x+1=0 1 roots");
}

void TestTwoRoots()
{
    AssertEqual(GetDistinctRealRootCount(2, 2, -5), 2, "2x^2+2x+1=0 2 roots");
    AssertEqual(GetDistinctRealRootCount(10, 50, 1), 2, "10x^2+50x+1=0 1 roots");
    AssertEqual(GetDistinctRealRootCount(-5, -2, 110), 2, "2x+1=0 1 roots");
}

int main()
{
    TestRunner tr;
    tr.RunTest(TestTwoRoots, "TestTwoRoots");
    tr.RunTest(TestNoRoots, "TestNoRoots");
    tr.RunTest(TestOneRoot, "TestOneRoot");
    return 0;
}