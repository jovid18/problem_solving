function solution(n, m, section) {
  let s;
  let answer = 0;
  for (let i = 0; i < section.length; ) {
    s = section[i];
    answer++;
    while (i < section.length && section[i] <= s + m - 1) {
      i++;
    }
  }
  return answer;
}
