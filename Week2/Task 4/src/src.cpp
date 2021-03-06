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

void TestRationalConstructing()
{
    AssertEqual(Rational().Denominator(), 1, "a");
    AssertEqual(Rational().Numerator(), 0, "a");
    AssertEqual(Rational(1, -2).Denominator(), 2, "c");
    AssertEqual(Rational(1, -2).Numerator(), -1, "c");
    AssertEqual(Rational(2, 3).Denominator(), 3, "d");
    AssertEqual(Rational(2, 3).Numerator(), 2, "d");
    AssertEqual(Rational(0, 10).Denominator(), 1, "e");
    AssertEqual(Rational(0, 10).Numerator(), 0, "e");
    AssertEqual(Rational(4, 6).Denominator(), 3, "b");
    AssertEqual(Rational(4, 6).Numerator(), 2, "b");
}

int main()
{
    TestRunner tr;
    tr.RunTest(TestRationalConstructing, "TestRationalConstructing");
    return 0;
}