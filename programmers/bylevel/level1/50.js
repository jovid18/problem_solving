function countDivisors(num) {
  let divisorCount = 0;
  for (let i = 1; i * i <= num; ++i) {
    if (i * i === num) {
      divisorCount++;
    } else if (num % i === 0) {
      divisorCount += 2;
    }
  }
  return divisorCount;
}

function solution(number, limit, power) {
  let totalPower = 0;
  for (let i = 1; i <= number; ++i) {
    let divisorCount = countDivisors(i);
    totalPower += divisorCount > limit ? power : divisorCount;
  }
  return totalPower;
}
