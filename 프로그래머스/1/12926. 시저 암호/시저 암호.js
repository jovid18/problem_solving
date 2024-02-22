function cipher(c, n) {
  if (c === ' ') {
    return ' ';
  } else if ('a' <= c && c <= 'z') {
    let ccode = c.charCodeAt(0);
    let acode = 'a'.charCodeAt(0);
    let diff = (ccode - acode + n) % 26;
    return String.fromCharCode(diff + acode);
  } else {
    let ccode = c.charCodeAt(0);
    let Acode = 'A'.charCodeAt(0);
    let diff = (ccode - Acode + n) % 26;
    return String.fromCharCode(diff + Acode);
  }
}

function solution(s, n) {
  var answer = '';
  for (let i = 0; i < s.length; ++i) {
    answer += cipher(s[i], n);
  }
  return answer;
}
