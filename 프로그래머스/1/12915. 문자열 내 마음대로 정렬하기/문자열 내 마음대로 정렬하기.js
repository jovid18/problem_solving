function solution(strings, n) {
  let stringsadd = strings.map((string) => {
    return string[n] + string;
  });
  stringsadd.sort((a, b) => {
    return a.localeCompare(b);
  });
  const answer = stringsadd.map((string) => {
    return (string = string.slice(1));
  });
  return answer;
}

let strings = ["sun", "bed", "car"];
solution(strings, 1);
