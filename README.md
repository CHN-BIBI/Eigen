# Welcome to Macren's Blog
###       ---Let's learn the eigen library！

Eigen is a C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms.


### Markdown

Basic operation of the Eigen library.

```markdown

# 输入数据
//     matrix_32(0,0) = 0;
//     matrix_32(0,1) = 1;
//     matrix_32(1,0) = 2;
//     matrix_32(1,1) = 10;
//     matrix_32(2,0) = 11; 
//     matrix_32(2,0) = 12; 

    matrix_32 << 1,2,3,4,5,6;              //The same function as the previous one.

# 矩阵操作
    /*四则运算*/                                                             //+、-、/ 同理
   //Matrix<float,3,1> multiply_result = matrix_32 * v_2d;                 //数据类型不同，不能直接操作
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

```

### Support or Contact

Having trouble with this Pages? You can get in touch with me by email：macren_bb@qq.com.
