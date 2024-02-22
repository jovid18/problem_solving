function solution(arr) {
  let answer = [];
  let minnum = Math.min(...arr);
  arr.forEach((e) => {
    if (e !== minnum) answer.push(e);
  });
  if (answer.length === 0) {
    answer.push(-1);
  }
  return answer;
}
