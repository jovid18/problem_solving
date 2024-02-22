function solution(t, p) {
  var answer = 0;
  for (let i = 0; i < t.length - p.length + 1; ++i) {
    let str = +t.substring(i, i + p.length);
    if (+str <= +p) answer++;
  }
  return answer;
}

