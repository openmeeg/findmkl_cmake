#include "Speaker.h"

#if defined USE_MKL

#include <mkl.h>
#include <mkl_lapacke.h>

#else

#ifdef __APPLE__
#include <Accelerate/Accelerate.h>
#else
#include <cblas.h>
#endif

#endif


#include <iomanip>
#include <sstream>

using namespace Hello;

namespace Hello {
  std::string Speaker::printBlasMatrix() {
    double A[6] = {1.0,2.0,1.0,-3.0,4.0,-1.0};
    double B[6] = {1.0,2.0,1.0,-3.0,4.0,-1.0};
    double C[9] = {.5,.5,.5,.5,.5,.5,.5,.5,.5};
    cblas_dgemm(CblasColMajor, CblasNoTrans, CblasTrans,3,3,2,1.,A,3,B,3,2.,C,3);

    std::ostringstream out;
    for(auto&& c:C)
      out << std::setprecision(3) << std::fixed <<  c << ' ';
    out << std::endl;

    return out.str();
  }

  void Speaker::sayHello() {
    std::cout << "Hello, world!\n";
    std::cout << printBlasMatrix() << std::endl;
  }
}
