function solution(numbers) {
  let sumPairs = [];
  for (let i = 0; i < numbers.length; ++i) {
    for (let j = 0; j < numbers.length; ++j) {
      if (i === j) continue;
    }
  }
  const uniqueSums = Array.from(new Set(sumPairs));
  uniqueSums.sort((a, b) => a - b);
  return uniqueSums;
}
