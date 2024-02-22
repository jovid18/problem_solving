function solution(s) {
  let answer = '';
  let arr = s.split(' ');
  for (let i = 0; i < arr.length; i++) {
    let arrString = arr[i];
    for (let j = 0; j < arrString.length; j++) {
      if (j % 2 === 0) {
        answer += arrString[j].toUpperCase();
      } else {
        answer += arrString[j].toLowerCase();
      }
    }
    if (i !== arr.length - 1) answer += ' ';
  }

  return answer;
}