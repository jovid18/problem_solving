function solution(n) {
  var answer = 0;
  //n=123
  while (n !== 0) {
    answer += n % 10; //3
    n /= 10; //12
    n = Math.floor(n);
  }
  return answer;
}
