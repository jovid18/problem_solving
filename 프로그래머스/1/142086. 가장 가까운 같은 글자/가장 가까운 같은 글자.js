function solution(s) {
  let obj = {};
  for (let i = 97; i <= 122; ++i) {
    let char = String.fromCharCode(i);
    obj[char] = -1;
  }
  let answer = [];
  [...s].forEach((element, index) => {
    if (obj[element] === -1) {
      answer.push(-1);
    } else {
      answer.push(index - obj[element]);
    }
    obj[element] = index;
  });
  return answer;
}

