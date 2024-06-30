#include <gtest/gtest.h>

#include <iostream>

#include "../3d_viewer_my/model/model.h"

TEST(Viewer, affins_move_1) {
  viewer::Model my_obj;
  std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
             std::vector<std::vector<int>>>
      answer = my_obj.ObjRead("test/test_cube.obj");

  std::vector<std::tuple<double, double, double>> origin_vectors;
  origin_vectors.push_back(std::tuple<double, double, double>{2, -1, -1});
  origin_vectors.push_back(std::tuple<double, double, double>{2, -1, 1});
  origin_vectors.push_back(std::tuple<double, double, double>{0, -1, 1});
  viewer::Difference diff = {1, 0, 0, 1, 0, 0, 0};
  std::vector<std::tuple<double, double, double>> result;
  result = my_obj.Recalculation(diff);
  for (int i = 0; i < 3; i++) {
    ASSERT_LT(abs(std::get<0>(result[i]) - std::get<0>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<1>(result[i]) - std::get<1>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<2>(result[i]) - std::get<2>(origin_vectors[i])),
              0.000001);
  }
}

TEST(Viewer, affins_move_2) {
  viewer::Model my_obj;
  std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
             std::vector<std::vector<int>>>
      answer = my_obj.ObjRead("test/test_cube.obj");
  std::vector<std::tuple<double, double, double>> origin_vectors;
  origin_vectors.push_back(std::tuple<double, double, double>{0, -1, -1});
  origin_vectors.push_back(std::tuple<double, double, double>{0, -1, 1});
  origin_vectors.push_back(std::tuple<double, double, double>{-2, -1, 1});
  viewer::Difference diff = {-1, 0, 0, 1, 0, 0, 0};
  std::vector<std::tuple<double, double, double>> result;
  result = my_obj.Recalculation(diff);
  for (int i = 0; i < 3; i++) {
    ASSERT_LT(abs(std::get<0>(result[i]) - std::get<0>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<1>(result[i]) - std::get<1>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<2>(result[i]) - std::get<2>(origin_vectors[i])),
              0.000001);
  }
}

TEST(Viewer, affins_move_3) {
  viewer::Model my_obj;
  std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
             std::vector<std::vector<int>>>
      answer = my_obj.ObjRead("test/test_cube.obj");
  std::vector<std::tuple<double, double, double>> origin_vectors;
  origin_vectors.push_back(std::tuple<double, double, double>{2, 0, 0});
  origin_vectors.push_back(std::tuple<double, double, double>{2, 0, 2});
  origin_vectors.push_back(std::tuple<double, double, double>{0, 0, 2});
  viewer::Difference diff = {1, 1, 1, 1, 0, 0, 0};
  std::vector<std::tuple<double, double, double>> result;
  result = my_obj.Recalculation(diff);
  for (int i = 0; i < 3; i++) {
    ASSERT_LT(abs(std::get<0>(result[i]) - std::get<0>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<1>(result[i]) - std::get<1>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<2>(result[i]) - std::get<2>(origin_vectors[i])),
              0.000001);
  }
}

TEST(Viewer, affins_size_1) {
  viewer::Model my_obj;
  std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
             std::vector<std::vector<int>>>
      answer = my_obj.ObjRead("test/test_cube.obj");
  std::vector<std::tuple<double, double, double>> origin_vectors;
  origin_vectors.push_back(std::tuple<double, double, double>{2, -2, -2});
  origin_vectors.push_back(std::tuple<double, double, double>{2, -2, 2});
  origin_vectors.push_back(std::tuple<double, double, double>{-2, -2, 2});
  viewer::Difference diff = {0, 0, 0, 2, 0, 0, 0};
  std::vector<std::tuple<double, double, double>> result;
  result = my_obj.Recalculation(diff);
  for (int i = 0; i < 3; i++) {
    ASSERT_LT(abs(std::get<0>(result[i]) - std::get<0>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<1>(result[i]) - std::get<1>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<2>(result[i]) - std::get<2>(origin_vectors[i])),
              0.000001);
  }
}

TEST(Viewer, affins_rotation_x_1) {
  viewer::Model my_obj;
  std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
             std::vector<std::vector<int>>>
      answer = my_obj.ObjRead("test/test_cube.obj");
  std::vector<std::tuple<double, double, double>> origin_vectors;
  origin_vectors.push_back(std::tuple<double, double, double>{1, -1, -1});
  origin_vectors.push_back(std::tuple<double, double, double>{1, -1, 1});
  origin_vectors.push_back(std::tuple<double, double, double>{-1, -1, 1});
  viewer::Difference diff = {0, 0, 0, 1, 0, 0, 0};
  std::vector<std::tuple<double, double, double>> result;
  result = my_obj.Recalculation(diff);
  for (int i = 0; i < 3; i++) {
    ASSERT_LT(abs(std::get<0>(result[i]) - std::get<0>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<1>(result[i]) - std::get<1>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<2>(result[i]) - std::get<2>(origin_vectors[i])),
              0.000001);
  }
}

TEST(Viewer, affins_rotation_x_2) {
  viewer::Model my_obj;
  std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
             std::vector<std::vector<int>>>
      answer = my_obj.ObjRead("test/test_cube.obj");
  std::vector<std::tuple<double, double, double>> origin_vectors;
  origin_vectors.push_back(std::tuple<double, double, double>{1, 1, 1});
  origin_vectors.push_back(std::tuple<double, double, double>{1, 1, -1});
  origin_vectors.push_back(std::tuple<double, double, double>{-1, 1, -1});
  viewer::Difference diff = {0, 0, 0, 1, M_PI, 0, 0};
  std::vector<std::tuple<double, double, double>> result;
  result = my_obj.Recalculation(diff);
  for (int i = 0; i < 3; i++) {
    ASSERT_LT(abs(std::get<0>(result[i]) - std::get<0>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<1>(result[i]) - std::get<1>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<2>(result[i]) - std::get<2>(origin_vectors[i])),
              0.000001);
  }
}

TEST(Viewer, affins_rotation_x_3) {
  viewer::Model my_obj;
  std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
             std::vector<std::vector<int>>>
      answer = my_obj.ObjRead("test/test_cube.obj");
  std::vector<std::tuple<double, double, double>> origin_vectors;
  origin_vectors.push_back(std::tuple<double, double, double>{1, 1, -1});
  origin_vectors.push_back(std::tuple<double, double, double>{1, -1, -1});
  origin_vectors.push_back(std::tuple<double, double, double>{-1, -1, -1});
  viewer::Difference diff = {0, 0, 0, 1, M_PI / 2, 0, 0};
  std::vector<std::tuple<double, double, double>> result;
  result = my_obj.Recalculation(diff);
  for (int i = 0; i < 3; i++) {
    ASSERT_LT(abs(std::get<0>(result[i]) - std::get<0>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<1>(result[i]) - std::get<1>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<2>(result[i]) - std::get<2>(origin_vectors[i])),
              0.000001);
  }
}

TEST(Viewer, affins_rotation_y_1) {
  viewer::Model my_obj;
  std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
             std::vector<std::vector<int>>>
      answer = my_obj.ObjRead("test/test_cube.obj");
  std::vector<std::tuple<double, double, double>> origin_vectors;
  origin_vectors.push_back(std::tuple<double, double, double>{1, -1, -1});
  origin_vectors.push_back(std::tuple<double, double, double>{1, -1, 1});
  origin_vectors.push_back(std::tuple<double, double, double>{-1, -1, 1});
  viewer::Difference diff = {0, 0, 0, 1, 0, 0, 0};
  std::vector<std::tuple<double, double, double>> result;
  result = my_obj.Recalculation(diff);
  for (int i = 0; i < 3; i++) {
    ASSERT_LT(abs(std::get<0>(result[i]) - std::get<0>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<1>(result[i]) - std::get<1>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<2>(result[i]) - std::get<2>(origin_vectors[i])),
              0.000001);
  }
}

TEST(Viewer, affins_rotation_y_2) {
  viewer::Model my_obj;
  std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
             std::vector<std::vector<int>>>
      answer = my_obj.ObjRead("test/test_cube.obj");
  std::vector<std::tuple<double, double, double>> origin_vectors;
  origin_vectors.push_back(std::tuple<double, double, double>{-1, -1, 1});
  origin_vectors.push_back(std::tuple<double, double, double>{-1, -1, -1});
  origin_vectors.push_back(std::tuple<double, double, double>{1, -1, -1});
  viewer::Difference diff = {0, 0, 0, 1, 0, M_PI, 0};
  std::vector<std::tuple<double, double, double>> result;
  result = my_obj.Recalculation(diff);
  for (int i = 0; i < 3; i++) {
    ASSERT_LT(abs(std::get<0>(result[i]) - std::get<0>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<1>(result[i]) - std::get<1>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<2>(result[i]) - std::get<2>(origin_vectors[i])),
              0.000001);
  }
}

TEST(Viewer, affins_rotation_y_3) {
  viewer::Model my_obj;
  std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
             std::vector<std::vector<int>>>
      answer = my_obj.ObjRead("test/test_cube.obj");
  std::vector<std::tuple<double, double, double>> origin_vectors;
  origin_vectors.push_back(std::tuple<double, double, double>{-1, -1, -1});
  origin_vectors.push_back(std::tuple<double, double, double>{1, -1, -1});
  origin_vectors.push_back(std::tuple<double, double, double>{1, -1, 1});
  viewer::Difference diff = {0, 0, 0, 1, 0, M_PI / 2, 0};
  std::vector<std::tuple<double, double, double>> result;
  result = my_obj.Recalculation(diff);
  for (int i = 0; i < 3; i++) {
    ASSERT_LT(abs(std::get<0>(result[i]) - std::get<0>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<1>(result[i]) - std::get<1>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<2>(result[i]) - std::get<2>(origin_vectors[i])),
              0.000001);
  }
}

TEST(Viewer, affins_rotation_z_1) {
  viewer::Model my_obj;
  std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
             std::vector<std::vector<int>>>
      answer = my_obj.ObjRead("test/test_cube.obj");
  std::vector<std::tuple<double, double, double>> origin_vectors;
  origin_vectors.push_back(std::tuple<double, double, double>{1, -1, -1});
  origin_vectors.push_back(std::tuple<double, double, double>{1, -1, 1});
  origin_vectors.push_back(std::tuple<double, double, double>{-1, -1, 1});
  viewer::Difference diff = {0, 0, 0, 1, 0, 0, 0};
  std::vector<std::tuple<double, double, double>> result;
  result = my_obj.Recalculation(diff);
  for (int i = 0; i < 3; i++) {
    ASSERT_LT(abs(std::get<0>(result[i]) - std::get<0>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<1>(result[i]) - std::get<1>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<2>(result[i]) - std::get<2>(origin_vectors[i])),
              0.000001);
  }
}

TEST(Viewer, affins_rotation_z_2) {
  viewer::Model my_obj;
  std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
             std::vector<std::vector<int>>>
      answer = my_obj.ObjRead("test/test_cube.obj");
  std::vector<std::tuple<double, double, double>> origin_vectors;
  origin_vectors.push_back(std::tuple<double, double, double>{-1, 1, -1});
  origin_vectors.push_back(std::tuple<double, double, double>{-1, 1, 1});
  origin_vectors.push_back(std::tuple<double, double, double>{1, 1, 1});
  viewer::Difference diff = {0, 0, 0, 1, 0, 0, M_PI};
  std::vector<std::tuple<double, double, double>> result;
  result = my_obj.Recalculation(diff);
  for (int i = 0; i < 3; i++) {
    ASSERT_LT(abs(std::get<0>(result[i]) - std::get<0>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<1>(result[i]) - std::get<1>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<2>(result[i]) - std::get<2>(origin_vectors[i])),
              0.000001);
  }
}

TEST(Viewer, affins_rotation_z_3) {
  viewer::Model my_obj;
  std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
             std::vector<std::vector<int>>>
      answer = my_obj.ObjRead("test/test_cube.obj");
  std::vector<std::tuple<double, double, double>> origin_vectors;
  origin_vectors.push_back(std::tuple<double, double, double>{1, 1, -1});
  origin_vectors.push_back(std::tuple<double, double, double>{1, 1, 1});
  origin_vectors.push_back(std::tuple<double, double, double>{1, -1, 1});
  viewer::Difference diff = {0, 0, 0, 1, 0, 0, M_PI / 2};
  std::vector<std::tuple<double, double, double>> result;
  result = my_obj.Recalculation(diff);
  for (int i = 0; i < 3; i++) {
    ASSERT_LT(abs(std::get<0>(result[i]) - std::get<0>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<1>(result[i]) - std::get<1>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<2>(result[i]) - std::get<2>(origin_vectors[i])),
              0.000001);
  }
}

TEST(Viewer, affins_mult_1) {
  viewer::Model my_obj;
  std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
             std::vector<std::vector<int>>>
      answer = my_obj.ObjRead("test/test_cube.obj");
  std::vector<std::tuple<double, double, double>> origin_vectors;
  origin_vectors.push_back(std::tuple<double, double, double>{4, -2, -2});
  origin_vectors.push_back(std::tuple<double, double, double>{4, -2, 2});
  origin_vectors.push_back(std::tuple<double, double, double>{0, -2, 2});
  viewer::Difference diff = {1, 0, 0, 2, 0, 0, 0};
  std::vector<std::tuple<double, double, double>> result;
  result = my_obj.Recalculation(diff);
  for (int i = 0; i < 3; i++) {
    ASSERT_LT(abs(std::get<0>(result[i]) - std::get<0>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<1>(result[i]) - std::get<1>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<2>(result[i]) - std::get<2>(origin_vectors[i])),
              0.000001);
  }
}

TEST(Viewer, affins_mult_2) {
  viewer::Model my_obj;
  std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
             std::vector<std::vector<int>>>
      answer = my_obj.ObjRead("test/test_cube.obj");
  std::vector<std::tuple<double, double, double>> origin_vectors;
  origin_vectors.push_back(std::tuple<double, double, double>{-2, 2, -2});
  origin_vectors.push_back(std::tuple<double, double, double>{-2, 2, 2});
  origin_vectors.push_back(std::tuple<double, double, double>{2, 2, 2});
  viewer::Difference diff = {0, 0, 0, 2, 0, 0, M_PI};
  std::vector<std::tuple<double, double, double>> result;
  result = my_obj.Recalculation(diff);
  for (int i = 0; i < 3; i++) {
    ASSERT_LT(abs(std::get<0>(result[i]) - std::get<0>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<1>(result[i]) - std::get<1>(origin_vectors[i])),
              0.000001);
    ASSERT_LT(abs(std::get<2>(result[i]) - std::get<2>(origin_vectors[i])),
              0.000001);
  }
}

TEST(Viewer, obj_reader_1) {
  viewer::Model my_obj;
  std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
             std::vector<std::vector<int>>>
      answer = my_obj.ObjRead("test/test_cube.obj");
  std::vector<std::tuple<double, double, double>> origin_vectors;
  origin_vectors.push_back(std::tuple<double, double, double>{1, -1, -1});
  origin_vectors.push_back(std::tuple<double, double, double>{1, -1, 1});
  origin_vectors.push_back(std::tuple<double, double, double>{-1, -1, 1});
  origin_vectors.push_back(std::tuple<double, double, double>{-1, -1, -1});
  origin_vectors.push_back(std::tuple<double, double, double>{1, 1, -0.999999});
  origin_vectors.push_back(std::tuple<double, double, double>{0.999999, 1, 1});
  origin_vectors.push_back(std::tuple<double, double, double>{-1, 1, 1});
  origin_vectors.push_back(std::tuple<double, double, double>{-1, 1, -1});
  ASSERT_EQ(std::get<0>(answer), 1);
  ASSERT_EQ(std::get<1>(answer), 8);
  ASSERT_EQ(std::get<2>(answer), 12);
  for (int i = 0; i < 3; i++) {
    ASSERT_LT(abs(std::get<0>(origin_vectors[i]) -
                  std::get<0>(std::get<3>(answer)[i])),
              0.000001);
    ASSERT_LT(abs(std::get<1>(origin_vectors[i]) -
                  std::get<1>(std::get<3>(answer)[i])),
              0.000001);
    ASSERT_LT(abs(std::get<2>(origin_vectors[i]) -
                  std::get<2>(std::get<3>(answer)[i])),
              0.000001);
  }
}

TEST(Viewer, obj_reader_2) {
  viewer::Model my_obj;
  std::tuple<bool, int, int, std::vector<std::tuple<double, double, double>>,
             std::vector<std::vector<int>>>
      answer = my_obj.ObjRead("dont_exist.obj");
  ASSERT_EQ(std::get<0>(answer), 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
