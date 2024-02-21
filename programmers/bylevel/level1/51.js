function solution(lottos, win_nums) {
  const zeroCount = lottos.filter((num) => num === 0).length; // 0의 개수를 센다
  const correctCount = lottos.filter((num) => win_nums.includes(num)).length; // 맞은 번호의 개수를 센다
  const maxRank = Math.min(6, 7 - (correctCount + zeroCount)); // 최대 등수 계산
  const minRank = Math.min(6, 7 - correctCount); // 최소 등수 계산

  return [maxRank, minRank];
}
