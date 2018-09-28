#include <iostream>
using namespace std;

#include <ctime>

#include <Eigen/Core>     //Eigen 部分
#include <Eigen/Dense>    //稠密矩阵的代数运算（逆，特征值等）
using    Eigen::Matrix;   //个人比较喜欢的声明方式，以避免个人定义的变量与库冲突
using    Eigen::VectorXd; //声明Xd时，定义是需要传入参数 VectorXd（维数）； x代表维数，d为double缩写，f为float

#define MATRIX_SIZE 50

int main(int argc, char **argv) 
{
    Matrix<float,3,2> matrix_32;    //声明一个3*2的矩阵
    VectorXd v_2d(2);               //声明一个3维向量,实质上是 Eigen::Matrix<double, 2, 1>
    
/***********************************************输入数据***********************************************/
//     matrix_32(0,0) = 0;
//     matrix_32(0,1) = 1;
//     matrix_32(1,0) = 2;
//     matrix_32(1,1) = 10;
//     matrix_32(2,0) = 11; 
//     matrix_32(2,0) = 12; 

    matrix_32 << 1,2,3,4,5,6;              //The same function as the previous one.
    //cout << matrix_32 << "\n";             //在使用cout输出时，只能有一个endl
    
    v_2d << 1,2;
    //cout << v_2d << "\n";
/****************************************************************************************************/  
 
/***********************************************矩阵操作***********************************************/
    /*四则运算*/                                                             //+、-、/ 同理
    // Matrix<float,3,1> multiply_result = matrix_32 * v_2d;                //数据类型不同，不能直接操作
    Matrix<float,3,1> multiply_result = matrix_32 * v_2d.cast<float>();     //应该显式转换,三个类型需要一致
    
    /*随机数矩阵*/
    Matrix<float,3,1> random_result = Eigen::Vector3d::Random().cast<float>();      
    //3d为3维的double，所以需要显示转换为float；这里的Eigen：：不加会报错
    //cout << random_result << "\n";
    
    /*矩阵的转置*/
    //cout << multiply_result.transpose() << "\n";                            //别漏了函数后的括号
    /*矩阵的元素和*/
    //cout << multiply_result.sum() << "\n";
    /*矩阵的迹*/
    //cout << multiply_result.trace() << "\n";                                //tr（A）= A特征值总和
    /*矩阵的数乘*/
    //cout << multiply_result * 10 << "\n"; 
    /*矩阵的逆*/                                                             
    //cout << (multiply_result * multiply_result.transpose()).inverse() << "\n"; //只有方阵才可逆
    /*矩阵的行列式*/
    //cout << (multiply_result * multiply_result.transpose()).determinant() << "\n";  //行列式一定是方阵
    /*共轭矩阵*/
    //cout << multiply_result.conjugate() << "\n";
    /*伴随矩阵*/
    //cout << multiply_result.adjoint() << "\n";
/****************************************************************************************************/  


//     Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> eigen_solver ((matrix_32.transpose()*matrix_32).cast<double>());
//     cout << "Eigen values = \n" << eigen_solver.eigenvalues() << endl;
//     cout << "Eigen vectors = \n" << eigen_solver.eigenvectors() << endl;

    
    return 0;
}
