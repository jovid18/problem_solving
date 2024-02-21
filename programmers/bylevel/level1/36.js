function solution(s) {
  var answer = s;
  num = { zero: "0", one: "1", two: "2", three: "3", four: "4", five: "5", six: "6", seven: "7", eight: "8", nine: "9" };
  for (let key in num) {
    let re = new RegExp(key, "g");
    answer = answer.replace(re, num[key]);
  }
  answer = Number(answer);
  return answer;
}
