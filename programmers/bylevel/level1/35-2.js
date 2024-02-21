function cipher(c, n) {
  //문자 c를 n만큼 밀어내기
  if (c === ' ') {
    //공백의 경우
    return ' ';
  } else if ('a' <= c && c <= 'z') {
    //소문자의 경우
    // 'a': 97 ,'b' :98 ,'c' : 99,...,'z':122
    // 'z': 122 를 3만큼 밀어보자 z->a->b->c 122->97->98->99
    // n:3
    let ccode = c.charCodeAt(0); //현재 문자의 아스키코드  //122
    let acode = 'a'.charCodeAt(0); // 소문자 a의 아스키코드 //97
    // fcode= ccode + n // 125  '}'
    // 여기가 포인트!

    // fcode = 97 +((122-97+3)%26)
    //       = 97 + (28%26)
    //       = 97 + 2
    //       = 99 =>c 잘 나왔다.
    let fcode = acode + ((ccode - acode + n) % 26); //위 둘의 차이에다가 n만큼 밀어내고 26으로 나눈 나머지에 소문자 a의 아스키 코드를 더해줌
    return String.fromCharCode(fcode); //최종 아스키 코드를 문자로 변환
  } else {
    // 대문자의 경우
    let ccode = c.charCodeAt(0); //현재 문자의 아스키 코드
    let Acode = 'A'.charCodeAt(0); // 대문자 A의 아스키 코드
    let fcode = Acode + ((ccode - Acode + n) % 26); //위 둘의 차이에다가 n만큼 밀어내고 26으로 나눈 나머지에 대문자 A의 아스키 코드를 더해줌
    return String.fromCharCode(fcode); // 최종 아스키 코드를 문자로 변환
  }
}

function solution(s, n) {
  var answer = '';
  // s:"A b" 이러면 하나씩 보고 answer에 'B',' ','c' 를 추가함.
  for (let i = 0; i < s.length; ++i) {
    answer += cipher(s[i], n);
  }
  return answer;
}
