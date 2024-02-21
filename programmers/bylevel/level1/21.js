function solution(n) {
  // 수박수박수박수박수박수?
  // 재훈님
  // let a = "수박"
  // n이 짝수일 때 a* (n/2)
  // 2 (수박)
  // 4 (수박)(수박)
  // 6 (수박)(수박)(수박)

  // n이 홀수일 때는 a*(n-1)/2
  // 1 수
  // 3 (수박)수
  // 5 (수박)(수박)수

  // answer +수
  let answer = '';
  let a = '수박';
  if (n % 2 === 0) {
    //
    for (let i = 0; i < n / 2; i++) {
      answer += a;
    }
  } else if (n % 2 === 1) {
    for (let i = 0; i < (n - 1) / 2; i++) {
      answer += a;
    }
    answer += '수';
  }
  return answer;
}
