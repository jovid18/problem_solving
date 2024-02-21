function solution(arr, divisor) {
  //arr / divisor % 0 => arr/divisor 나눈 arr을 return : 우정
  //1. answer에 나누어 떨어지는 값의 배열 push

  //answer.push : 오름차순 정렬
  let answer = [];
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] % divisor === 0) {
      answer.push(arr[i]);
    }
  }
  // if (Array.isArray(answer) && answer.length === 0) {

  // }

  if (answer.length === 0) {
    answer.push(-1);
  }
  return answer.sort((a, b) => a - b);
}

// Array.isArray(arr) && arr.length === 0
