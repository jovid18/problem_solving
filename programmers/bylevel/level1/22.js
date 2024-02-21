function solution(a, b) {
  // 내적
  // for문 사용
  // sum += a[i]*b[i]
  let answer = 0;
  for (let i = 0; i < a.length; ++i) {
    answer += a[i] * b[i];
  }

  return answer;
}
