#include <Eigen/Core>

namespace XCG{
    template <typename DerivedF, typename VFType, typename VFiType>
    inline void vertex_triangle_adjacency(
  const typename DerivedF::Scalar n,
  const Eigen::MatrixBase<DerivedF>& F,
  std::vector<std::vector<VFType> >& VF,
  std::vector<std::vector<VFiType> >& VFi)
  {
    VF.clear();
    VFi.clear();
    VF.resize(n);
    VFi.resize(n);

    typedef typename DerivedF::Index Index;
    for(Index fi=0; fi<F.rows(); ++fi)
    {
        for(Index i = 0; i < F.cols(); ++i)
        {
        VF[F(fi,i)].push_back(fi);
        VFi[F(fi,i)].push_back(i);
        }
    }
  }

}