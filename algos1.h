#include "base.h"

std::string addint1(std::string x, std::string x2) {
  bool is_grt = is_greater(x, x2);
  unsigned int n = x.length();
  unsigned int n2 = x2.length();
  unsigned int cur_idx;
  std::vector<unsigned int> ref_add;
  std::vector<unsigned int> to_add;
  unsigned int ref_max = 999999999;
  unsigned int ref_max2 = 1000000000;
  unsigned int cur_rslt;
  unsigned int cur_rslt2;
  unsigned int cur_rslt3;
  int cnt;
  int cnt2;
  unsigned int mltp;
  unsigned int n_min;
  unsigned int n_max;
  bool agn;
  std::string rtn_str = "";
  std::string cur_str;
  if (is_grt) {
    cnt = 1;
    cur_idx = 0;
    while (cnt < n + 1) {
      cnt2 = 1;
      ref_add.push_back(int(x[n - cnt]) - 48);
      mltp = 10;
      while (cnt2 + cnt < n + 1 & cnt2 < 9) {
        ref_add[cur_idx] += (int(x[n - cnt - cnt2]) - 48) * mltp;
        mltp *= 10;
        cnt2 += 1;
      };
      cnt += 9;
      cur_idx += 1;
    };
    cnt = 1;
    cur_idx = 0;
    while (cnt < n2 + 1) {
      cnt2 = 1;
      to_add.push_back(int(x2[n2 - cnt]) - 48); 
      mltp = 10;
      while (cnt2 + cnt < n2 + 1 & cnt2 < 9) {
        to_add[cur_idx] += (int(x2[n2 - cnt - cnt2]) - 48) * mltp;
        mltp *= 10;
        cnt2 += 1;
      };
      cnt += 9;
      cur_idx += 1;
    };
  } else {
    cnt = 0;
    while (cnt < n) {
      cnt2 = 1;
      ref_add.push_back(int(x2[n2 - cnt]) - 48); 
      mltp = 10;
      while (cnt2 < n & cnt2 < 9) {
        ref_add[cur_idx] += (int(x[n - cnt - cnt2]) - 48) * mltp;
        mltp *= 10;
        cnt2 += 1;
      };
      n += 9;
    };
    cnt = 0;
    while (cnt < n2) {
      cnt2 = 1;
      to_add.push_back(int(x[n - cnt]) - 48); 
      mltp = 10;
      while (cnt2 + cnt < n2 & cnt2 < 9) {
        to_add[cur_idx] += (int(x2[n2 - cnt - cnt2]) - 48) * mltp;
        mltp *= 10;
        cnt2 += 1;
      };
      n += 9;
    };
  };
  n_max = ref_add.size();
  n_min = to_add.size();
  for (cnt = 0; cnt < n_min; ++cnt) {
    cur_rslt = ref_add[cnt] + to_add[cnt];
    if (cur_rslt > ref_max) {
      cnt2 = 1;
      ref_add[cnt] = cur_rslt - ref_max2;
      cur_rslt = ref_add[cnt + cnt2] + 1;
      agn = 1;
      while (agn) {
        if (cur_rslt < ref_max2) {
          ref_add[cnt + cnt2] = cur_rslt;
          agn = 0;
        } else {
          ref_add[cnt + cnt2] = 0;
          cnt2 += 1; 
          if (cnt + cnt2 < n_max) {
            ref_add.push_back(1);
            n_max += 1;
            agn = 0;
          } else {
            cur_rslt = ref_add[cnt + cnt2] + 1;
          };
        };
      };
    } else {
      ref_add[cnt] = cur_rslt;
    };
  };
  for (cnt = 0; cnt < n_max; ++cnt) {
    cur_rslt = ref_add[cnt];
    cur_rslt3 = cur_rslt;
    cur_str = "";
    while(10 < cur_rslt3) {
      cur_rslt2 = cur_rslt3 % 10;
      cur_str.insert(0, 1, char(cur_rslt2 + 48));
      cur_rslt3 -= cur_rslt2;
      cur_rslt3 /= 10;
    };
    cur_rslt2 = cur_rslt3 % 10;
    cur_str.insert(0, 1, char(cur_rslt2 + 48));
    rtn_str = cur_str + rtn_str;
  };
  return rtn_str;
};


