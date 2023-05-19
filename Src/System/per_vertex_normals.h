#include <Eigen/Core>


namespace XCG
{

    template <typename DerivedV, typename DerivedF, typename DerivedN>
    inline void per_vertex_normal(
        const Eigen::MatrixBase<DerivedV>& V,
        const Eigen::MatrixBase<DerivedF>& F,
        Eigen::PlainObjectBase<DerivedN> & N)
    {
        using namespace std;
        N.setZero(V.rows(),3);

        Eigen::Matrix<typename DerivedN::Scalar,DerivedF::RowsAtCompileTime,3>
        W(F.rows(),3);

          // loop over faces
        for(int i = 0;i<F.rows();i++)
        {
            // throw normal at each corner
            for(int j = 0; j < 3;j++)
            {
            N.row(F(i,j)) += W(i,j) * FN.row(i);
            }
        }

          N.rowwise().normalize();
    }

}