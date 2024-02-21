function solution(numbers) {
  // 없는 숫자 더하기
  let answer = 0;
  for (let i = 0; i < numbers.length; i++) {
    answer += numbers[i];
  }
  return 45 - answer;
}
//n(n+1)/2;