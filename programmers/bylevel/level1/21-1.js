function solution(n) {
  // 홀수일 때 => 수
  // 짝수일 때 => 박
  // ==> 반복
  let answer = '';
  for (let i = 0; i < n; ++i) {
    answer += i % 2 === 0 ? '수' : '박';
  }
  return answer;
}
