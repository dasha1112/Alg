#include "Vector.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector <int> v(3));
}

TEST(TVector, throws_when_create_vector_with_negative_length) {
    ASSERT_ANY_THROW(TVector<int> m(-5));
}

TEST(TVector, can_get_length)
{
  TVector <int> v(3);

  EXPECT_EQ(3, v.Size());
}

TEST(TVector, can_create_copied_vector) {
    TVector<int> v(5);

    ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, assign_operator_change_vector_size) {
    TVector<int> v(5);
    EXPECT_EQ(v.Size(), 5);
    v.Resize(4);
    EXPECT_EQ(v.Size(), 4);
}
TEST(TVector, can_sum_vector)
{
  TVector <int> v_1(3);
  for (int i = 0; i < v_1.Size(); i++) 
  {
      v_1[i] = i;
  }

  TVector <int> v_2(3);
  for (int i = 0; i < v_2.Size(); i++)
  {
      v_2[i] = i;
  }

  TVector <int> vec_res(3);
  vec_res = v_1 + v_2;
  ASSERT_EQ(vec_res[0], 0);
  ASSERT_EQ(vec_res[1], 2);
  ASSERT_EQ(vec_res[2], 4);
}

TEST(TVector, can_minus_vector)
{
    TVector <int> v_1(3);
    v_1 [0] = 2;
    v_1 [1] = 4;
    v_1[2] = 6;

    TVector <int> v_2(3);
    v_2[0] = 1;
    v_2[1] = 2;
    v_2[2] = 3;


    TVector <int> vec_res(3);
    vec_res = v_1 - v_2;
    ASSERT_EQ(vec_res[0], 1);
    ASSERT_EQ(vec_res[1], 2);
    ASSERT_EQ(vec_res[2], 3);
}

TEST(TVector, can_proizv_vector)
{
    TVector <int> v_1(3);
    for (int i = 0; i < v_1.Size(); i++)
    {
        v_1[i] = i;
    }

    TVector <int> v_2(3);
    for (int i = 0; i < v_2.Size(); i++)
    {
        v_2[i] = i;
    }

    TVector <int> vec_res(3);
    vec_res = v_1 * v_2;
    ASSERT_EQ(vec_res[0], 0);
    ASSERT_EQ(vec_res[1], 1);
    ASSERT_EQ(vec_res[2], 4);
}


TEST(TVector, equality_operator_test)
{
    TVector <int> v_1(3);
    v_1[0] = 2;
    v_1[1] = 4;
    v_1[2] = 6;

    TVector <int> v_2(3);
    v_2[0] = 2;
    v_2[1] = 4;
    v_2[2] = 6;

    TVector <int> v_3(3);
    v_3[0] = 1;
    v_3[1] = 2;
    v_3[2] = 3;

    ASSERT_TRUE(v_1 == v_2); 
    ASSERT_FALSE(v_1 == v_3);
}

TEST(TVector, can_sum_double)
{
    TVector <int> v_1(3);
    v_1[0] = 2;
    v_1[1] = 4;
    v_1[2] = 6;

    double d = 2;


    TVector <int> vec_res(3);
    vec_res = v_1 + d;
    ASSERT_EQ(vec_res[0], 4);
    ASSERT_EQ(vec_res[1], 6);
    ASSERT_EQ(vec_res[2], 8);
}

TEST(TVector, can_sum_double)
{
    TVector <int> v_1(3);
    v_1[0] = 2;
    v_1[1] = 4;
    v_1[2] = 6;

    double d = 2;


    TVector <int> vec_res(3);
    vec_res = v_1 + d;
    ASSERT_EQ(vec_res[0], 4);
    ASSERT_EQ(vec_res[1], 6);
    ASSERT_EQ(vec_res[2], 8);
}

TEST(TVector, can_min_double)
{
    TVector <int> v_1(3);
    v_1[0] = 2;
    v_1[1] = 4;
    v_1[2] = 6;

    double d = 2;


    TVector <int> vec_res(3);
    vec_res = v_1 - d;
    ASSERT_EQ(vec_res[0], 0);
    ASSERT_EQ(vec_res[1], 2);
    ASSERT_EQ(vec_res[2], 4);
}

TEST(TVector, can_min_double)
{
    TVector <int> v_1(3);
    v_1[0] = 2;
    v_1[1] = 4;
    v_1[2] = 6;

    double d = 2;


    TVector <int> vec_res(3);
    vec_res = v_1 - d;
    ASSERT_EQ(vec_res[0], 0);
    ASSERT_EQ(vec_res[1], 2);
    ASSERT_EQ(vec_res[2], 4);
}

TEST(TVector, can_proizv_double)
{
    TVector <int> v_1(3);
    v_1[0] = 2;
    v_1[1] = 4;
    v_1[2] = 6;

    double d = 2;


    TVector <int> vec_res(3);
    vec_res = v_1 - d;
    ASSERT_EQ(vec_res[0], 4);
    ASSERT_EQ(vec_res[1], 8);
    ASSERT_EQ(vec_res[2], 12);
}