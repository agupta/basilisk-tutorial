#include "saint-venant.h"

event init (t = 0) {
  foreach()
    // Gaussian bump of characteristic radius 1/sqrt(200) on top of a layer of
    // constant depth 0.1
    h[] = 0.1 + 1.*exp(-200.*(x*x + y*y));
}

event graphs (i++) {
  stats s = statsf (h);
  // write min and max to stderr for each t
  fprintf (stderr, "%g %g %g\n", t, s.min, s.max);
}

event images (t += 4./300.) {
  output_ppm(h, linear=true);
  scalar l[];
  foreach()
    l[] = level;
  // output grid to grid.ppm
  static FILE * fp = fopen ("grid.ppm", "w");
  output_ppm (l, fp, min = 0, max = 8);
}
event end (t = 4) {
  printf("i = %d t = %g\n", i, t);
}

event adapt (i++) {
  adapt_wavelet ({h}, (double []){4e-3}, maxlevel = 8);
}

int main() {
  origin (-0.5, -0.5);
  init_grid (256);
  run();
}