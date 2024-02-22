function solution(numbers) {
    let sumPairs = []; // 두 수의 합을 저장할 임시 배열
    for (let i = 0; i < numbers.length; ++i) {
      for (let j = 0; j < numbers.length; ++j) {
        if (i === j) continue; // 같은 인덱스의 수는 더하지 않음
        sumPairs.push(numbers[i] + numbers[j]);
      }
    }
    const uniqueSums = Array.from(new Set(sumPairs)); // 중복 제거
    uniqueSums.sort((a, b) => a - b); // 오름차순 정렬
    return uniqueSums;
  }