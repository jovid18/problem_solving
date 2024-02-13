function solution(answers) {
  let answer = [];
  let students = [
    [1, 2, 3, 4, 5, 1, 2, 3, 4, 5],
    [2, 1, 2, 3, 2, 4, 2, 5],
    [3, 3, 1, 1, 2, 2, 4, 4, 5, 5],
  ];
  let score = [0, 0, 0];
  for (let i = 0; i < answers.length; ++i) {
    for (let j = 0; j < 3; ++j) {
      if (answers[i] === students[j][i % students[j].length]) {
        score[j]++;
      }
    }
  }
  const MaxScore = Math.max(...score);
  for (let i = 0; i < 3; ++i) {
    if (MaxScore === score[i]) answer.push(i + 1);
  }
  return answer;
}
