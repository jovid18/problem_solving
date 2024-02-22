function __gcd(x, y) {
  if (x < y) [x, y] = [y, x];
  if (y == 0) return x;
  else return __gcd(y, x % y);
}

function solution(n, m) {
  let gcd = __gcd(n, m);
  let lcm = (n * m) / gcd;
  return [gcd, lcm];
}
