function solution(x) {
  //하샤드 수
  //각 자리수의 합을 구하고
  //그거로 x를 나눠지는지 확인!
  let copyx = x;
  let sum = 0;

  while (copyx !== 0) {
    sum += copyx % 10;
    copyx /= 10;
    copyx = Math.floor(copyx);
  }
  if (x % sum === 0) {
    return true;
  }
  return false;
}
