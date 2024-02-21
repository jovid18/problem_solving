//유클리드 호제법
function __gcd(x, y) {
  //x가 무조건 y보다 커야함
  if (x < y) [x, y] = [y, x];
  if (y == 0) return x;
  else return __gcd(y, x % y);
}

function solution(n, m) {
  // 최대공약수와 최소공배수
  // 이 문제의 핵심은 최대 공약수를 아는 것
  // 2번째 방법
  // 유클리드 호제법을 이용해서 최대 공약수를 빠르게 구할 수 있다.
  let gcd = __gcd(n, m);
  let lcm = (n * m) / gcd;
  return [gcd, lcm];
}
