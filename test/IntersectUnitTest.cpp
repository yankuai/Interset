#include "pch.h"
#include "CppUnitTest.h"
#include "../intersect.h"
#include<set>
#include<iostream>
extern class Line;
class Point;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntersectUnitTest
{
	TEST_CLASS(IntersectUnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Line l1(Point(0, 0), Point(1, 1));
			Line l2(Point(0, 1), Point(2, 1));
			set<Point> intersections;
			l1.getIntersection_ll(&intersections, l1, l2);
			set<Point>::iterator it = intersections.begin();
			Assert::AreEqual((int)intersections.size(), 1);
			Assert::AreEqual(it->first, 1.0);
			Assert::AreEqual(it->second, 1.0);
		}
		//两直线平行
		TEST_METHOD(TestMethod2)
		{
			Line l1(Point(0, 0), Point(1, 1));
			Line l2(Point(-1, 0), Point(0, 1));
			set<Point> intersections;
			l1.getIntersection_ll(&intersections, l1, l2);
			Assert::AreEqual((int)intersections.size(), 0);
		}
		//直线斜率为无穷
		TEST_METHOD(TestMethod3)
		{
			Line l1(Point(0, 0), Point(1, 1));
			Line l2(Point(1, 0), Point(1, 2));
			set<Point> intersections;
			l1.getIntersection_ll(&intersections, l1, l2);
			set<Point>::iterator it = intersections.begin();
			Assert::AreEqual((int)intersections.size(), 1);
			Assert::AreEqual(it->first, 1.0);
			Assert::AreEqual(it->second, 1.0);
		}
		//两圆相离
		TEST_METHOD(TestMethod4)
		{
			Circle c1(Point(0, 0), 1);
			Circle c2(Point(3, 3), 2);
			set<Point> intersections;
			c1.getIntersection_cc(&intersections, c1, c2);
			Assert::AreEqual((int)intersections.size(), 0);
		}
		//两圆嵌套
		TEST_METHOD(TestMethod5)
		{
			Circle c1(Point(0, 0), 3);
			Circle c2(Point(0, 0), 2);
			set<Point> intersections;
			c1.getIntersection_cc(&intersections, c1, c2);
			Assert::AreEqual((int)intersections.size(), 0);
		}
		//两圆相切
		TEST_METHOD(TestMethod6)
		{
			Circle c1(Point(0, 0), 2);
			Circle c2(Point(1, 0), 1);
			set<Point> intersections;
			c1.getIntersection_cc(&intersections, c1, c2);
			set<Point>::iterator it = intersections.begin();
			Assert::AreEqual((int)intersections.size(), 1);
			Assert::AreEqual(it->first, 2.0);
			Assert::AreEqual(it->second, 0.0);
		}
		//两圆相交于两点
		TEST_METHOD(TestMethod7)
		{
			Circle c1(Point(0, 0), 2);
			Circle c2(Point(2, 0), 2);
			set<Point> intersections;
			c1.getIntersection_cc(&intersections, c1, c2);
			Assert::AreEqual((int)intersections.size(), 2);
		}
		//圆与直线相离
		TEST_METHOD(TestMethod8)
		{
			Circle c(Point(0, 0), 1);
			Line l(Point(2, 0), Point(2, 1));
			set<Point> intersections;
			getIntersection_cl(&intersections, c, l);
			cout << intersections.size();
			Assert::AreEqual((int)intersections.size(), 0);
		}
		//圆与直线相切
		TEST_METHOD(TestMethod9)
		{
			Circle c(Point(0, 0), 1);
			Line l(Point(1, 0), Point(1, 1));
			set<Point> intersections;
			getIntersection_cl(&intersections, c, l);
			set<Point>::iterator it = intersections.begin();
			cout << intersections.size();
			Assert::AreEqual((int)intersections.size(), 1);
			Assert::AreEqual(it->first, 1.0);
			Assert::AreEqual(it->second, 0.0);
		}
		//圆与直线相交于两点
		TEST_METHOD(TestMethod10)
		{
			Circle c(Point(0, 0), 1);
			Line l(Point(0, 0), Point(0, 1));
			set<Point> intersections;
			getIntersection_cl(&intersections, c, l);
			set<Point>::iterator it = intersections.begin();
			Assert::AreEqual((int)intersections.size(), 2);
		}
	};
}
