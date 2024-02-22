function solution(numbers) {
  const sum = numbers.reduce((accumulator, currentValue) => accumulator + currentValue, 0);

  return 45 - sum;
}
