function solution(players, callings) {
  let PtoR = {};
  let RtoP = {};
  players.forEach((e, idx) => {
    idx++;
    PtoR[e] = idx;
    RtoP[idx] = e;
  });
  callings.forEach((e) => {
    let [aname, arank] = [e, PtoR[e]];
    let [bname, brank] = [RtoP[arank - 1], arank - 1];
    PtoR[aname] = brank;
    PtoR[bname] = arank;
    RtoP[arank] = bname;
    RtoP[brank] = aname;
  });
  var answer = [];
  for (let i = 1; i <= players.length; ++i) {
    answer.push(RtoP[i]);
  }
  return answer;
}
