#include <iostream>

using namespace std;

#include <ctime>
// Eigen 核心部分
#include <Eigen/Core>
// 稠密矩阵的代数运算（逆，特征值等）
#include <Eigen/Dense>

using namespace Eigen;

int main(int argc, char **argv) {

     cout << "RPY对应滚动角，副下" << endl;
     cout << "读取到的r:" << argv[1] << endl;
     cout << "读取到的p:" << argv[2] << endl;
     cout << "读取到的y:" << argv[3] << endl;

     Eigen::Vector3d RPY(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));

     cout << "欧拉角向量：" << RPY.transpose() << endl;

     RPY = RPY * M_PI / 180;


     /**
      * 已知坐标系A和坐标系B，其中B是由A先通过Z轴旋转 γ 度，
      * 再在旋转后坐标的基础上沿Y轴旋转 β 度，
      * 再此基础上再沿X轴旋转 α 度，
      * 则两坐标系之间的旋转矩阵 R_{AB} ​可由下式求得：
      *   R_{AB} = R_z {γ} * R_y {β} * R_x {α}
     */
     Eigen::Matrix3d R_AB;

     //输入部分为 RPY , 所以转换的输出也是 RPY
     R_AB = Eigen::AngleAxisd(RPY[2], Eigen::Vector3d::UnitZ()) * 
          Eigen::AngleAxisd(RPY[1], Eigen::Vector3d::UnitY()) * 
          Eigen::AngleAxisd(RPY[0], Eigen::Vector3d::UnitX());
     RPY = R_AB.eulerAngles(2, 1, 0);

     cout << RPY.transpose() * 180 / M_PI << endl;

     return 0;
}