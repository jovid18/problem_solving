function solution(n) {
  var answer = 0;
  // let string = n.split('');
  let string = String(n).split('');
  for (let i = 0; i < string.length; ++i) {
    answer += Number(string[i]);
  }

  return answer;
}