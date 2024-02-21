function solution(n) {
  //n을 x로 나눈 나머지가 1이 되도록 하는 -> for문 (n % x === 1)
  //가장 작은 자연수 x를 return 하도록
  //n이 홀수 일때는 return 2;
  let x = 1;
  while (true) {
    if (n % x === 1) return x;
    x++;
  }
}
