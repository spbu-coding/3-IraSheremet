#include <stdio.h>
#include <math.h>

struct answersf_t {
float x1;
float x2;
};
struct answers_t {
double x1;
double x2;
};

float solve_in_float(float delta, struct answersf_t *answersf) {
  answersf->x2 = (2.0001f - 2.0f + delta) / (1.0001f - 1.0f);
  answersf->x1 = 2.0f - (2.0001f - 2.0f + delta) / (1.0001f - 1.0f);
  return sqrtf((1.0f - answersf->x2) * (1.0f - answersf->x2) + (1.0f - answersf->x1) * (1.0f - answersf->x1));
}
float solve_in_double(double delta, struct answers_t *answers) {
  answers->x2 = (2.0001 - 2.0 + delta) / (1.0001 - 1.0);
  answers->x1 = 2.0 - (2.0001 - 2.0 + delta) / (1.0001 - 1.0);
  return sqrt((1.0 - answers->x2) * (1.0 - answers->x2) + (1.0 - answers->x1) * (1.0 - answers->x1));
}

int main(){
  float decision_deviation_float, delta_float = 0.0001f;
  struct answersf_t answersf = {0, 0};
  int count = 1;
  double decision_deviation, delta = 0.0001;
  struct answers_t answers = {0, 0};
  do {
    decision_deviation_float = solve_in_float(delta_float, &answersf);
    printf("Experiment in float %d:\n", count);
    printf("x1 is %.16f, x2 is %.16f, delta is %.16f\n", answersf.x1, answersf.x2, delta_float);
    printf("Deviation from the original decision is %.16f\n", decision_deviation_float);
    delta_float /= 2;
    decision_deviation = solve_in_double(delta, &answers);
    printf("Experiment in double %d:\n", count);
    printf("x1 is %.16lf, x2 is %.16lf, delta is %.16lf\n", answers.x1, answers.x2, delta);
    printf("Deviation from the original decision is %.16lf\n", decision_deviation);
    printf("________________________________________________\n");
    delta /= 2;
    count++;
  } while ((decision_deviation_float >= 0.000001f) || (decision_deviation >= 0.000001));
  return 0;
}
