function solution(numbers) {
  // 없는 숫자 더하기
  //
  const sum = numbers.reduce((accumulator, currentValue) => accumulator + currentValue, 0);
  return 45 - sum;
}
