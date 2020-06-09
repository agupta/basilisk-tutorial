#include "saint-venant.h"

event init (t = 0) {
  foreach()
    // Gaussian bump of characteristic radius 1/sqrt(200) on top of a layer of
    // constant depth 0.1
    h[] = 0.1 + 1.*exp(-200.*(x*x + y*y));
}

event graphs (i++) {
  stats s = statsf (h);
  fprintf (stderr, "%g %g %g\n", t, s.min, s.max);
}

event images (i++) {
  output_ppm (h);
}
event end (i=300) {
  printf("i = %d t = %g\n", i, t);
}

int main() {
  origin (-0.5, -0.5);
  init_grid (256);
  run();
}