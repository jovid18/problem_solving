function solution(n, m) {
  // 최대공약수와 최소공배수
  // 최대공약수 :gcd
  // 최소공배수 :lcm
  // 이 문제의 핵심은 최대 공약수를 아는 것
  // 1번째 방법
  // for 문 돌려서 1부터 min(n,m) 까지 돌려서 공약수중에 최대를 찾는 것
  // 2번째 방법 유클리드 호제법 -> 29-1 로!
  let gcd = 0;
  let lcm = 0;
  for (let i = Math.min(n, m); i >= 1; --i) {
    if (n % i === 0 && m % i === 0) {
      gcd = i;
      break;
    }
  }
  // a : 12 b : 16 => gcd :4 lcm:48
  // a * b = gcd * lcm
  // lcm = a * b / gcd
  lcm = (n * m) / gcd;
  return [gcd, lcm];
}
