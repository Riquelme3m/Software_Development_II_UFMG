#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../triangle.hpp"

using shapes::Triangle;

TEST_CASE("Testing getPerimeter()")
{
    Triangle i = Triangle(5, 3, 3);
    CHECK_EQ(11, i.getPerimeter());
}

TEST_CASE("Testing getArea()")
{
    Triangle i = Triangle(5, 3, 3);
    CHECK_EQ(i.getArea(), doctest::Approx(4.14).epsilon(0.01));
    Triangle j = Triangle(7, 6, 5);
    CHECK_EQ(j.getArea(), doctest::Approx(14.7).epsilon(0.01));
}
TEST_CASE("Testing getKind()")
{
    Triangle equilateral = Triangle(4, 4, 4);
    Triangle isosceles = Triangle(5, 3, 3);
    Triangle escalene = Triangle(7, 6, 5);

    CHECK_EQ(equilateral.getKind(), Triangle::Kind::EQUILATERAL);
    CHECK_EQ(isosceles.getKind(), Triangle::Kind::ISOSCELES);
    CHECK_EQ(escalene.getKind(), Triangle::Kind::SCALENE);
}