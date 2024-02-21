function solution(n) {
  //정수 n을 입력받아 n의 약수를 모두 더한 값을 리턴하는 함수,
  //solution을 완성해주세요.
  //1부터 n까지를  for문 돌려서 n%i==0 i가 약수라는 거니까 이떄 더해주면 될것 같은?
  var answer = 0;
  // for (let i = 1; i <= n; i++) {
  //   if (n % i === 0) {
  //     answer += i;
  //   }
  // }
  for (let i = 1; i * i <= n; ++i) {
    if (i * i === n) answer++;
    else if (n % i == 0) answer += 2;
  }
  return answer;
}
//소수의 경우 => 에라토스테네스의 체
