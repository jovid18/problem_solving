function solution(arr) {
  // 제일 작은 수 제거하기
  // 최소값 = Math.min(arr)로 구하기
  // 최소값이 아닌 배열의 요소를 answer에 넣기
  let answer = [];
  let minnum = Math.min(...arr); //Math.min(arr)가 아니라 ...arr를 이용
  arr.forEach((e) => {
    if (e !== minnum) answer.push(e);
  });
  if (answer.length === 0) {
    answer.push(-1);
  }
  return answer;
}

