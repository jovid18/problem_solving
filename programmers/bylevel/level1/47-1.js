function solution(answers) {
  const students = [
    [1, 2, 3, 4, 5],
    [2, 1, 2, 3, 2, 4, 2, 5],
    [3, 3, 1, 1, 2, 2, 4, 4, 5, 5],
  ];
  let arr = [],
    result = [];
  for (const i in students) {
    let check = 0;
    for (const j in answers) {
      if (students[i][j] === answers[j]) check++;
    }
    arr.push([i, check]);
  }
  arr.sort((a, b) => b[1] - a[1]);
  result.push(Number(arr[0][0]) + 1);
  for (let i = 0; i < arr.length - 1; i++) {
    if (arr[i][1] === arr[i + 1][1]) {
      result.push(Number(arr[i + 1][0]) + 1);
    } else break;
  }

  return result;
}
let answers = [1, 2, 3, 3, 2, 2, 1, 1, 2, 3, 4, 5];
