#include <iostream>

using namespace std;

#include <ctime>
// Eigen 核心部分
#include <Eigen/Core>
// 稠密矩阵的代数运算（逆，特征值等）
#include <Eigen/Dense>

using namespace Eigen;

int main(int argc, char **argv) {
     Quaterniond q(0.35, 0.2, 0.3, 0.1);
     Matrix3d R = q.normalized().toRotationMatrix();

     cout << "Quaternion2RotationMatrix result is:" << endl;
     cout << "R = " << endl << R << endl;
     cout << "R transpose = \n" << R.transpose() << endl;      // 转置
     cout << "R inverse = \n" << R.inverse() << endl;        // 逆

     Matrix3d R_result = R * R.transpose();
     cout << "R * R transpose = \n" << R_result << endl; 

     Matrix3d I = Matrix3d::Identity(3, 3);
     cout << "3*3 Identity = \n" << I << endl; 

     cout << "R * R transpose = I" << endl;
     cout << "The Rotation Matrix is an orthogonal matrix \n" << endl;  
     
       // 解方程
     // 求解 matrix_C * x = b 这个方程
     // N的大小在前边的宏里定义，它由随机数生成
     // 直接求逆自然是最直接的，但是求逆运算量大

     Matrix3d matrix_C;
     matrix_C  << 1, 2, 3, 3, 1, 2, 1, 2, 0;
     cout << "matrix_C = \n" << matrix_C << endl;    
     Vector3d b;
     b << 14, 11, 5;
     cout << "b = \n" << b << endl;    

     // 直接求逆
     Matrix<double, 3, 1> x = matrix_C.inverse() * b;
     cout << "方程组运行结果" << endl;
     cout << "x = " << x.transpose() << endl;


     return 0;
}