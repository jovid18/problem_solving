function solution(absolutes, signs) {
  //음양 더하기
  let answer = 0;
  for (let i = 0; i < absolutes.length; ++i) {
    answer += signs[i] ? absolutes[i] : -absolutes[i];
  }
  return answer;
}
//sign에 따라 -1 곱하는 방식도 