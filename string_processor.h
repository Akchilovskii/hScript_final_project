#pragma once
#include<boost/utility/string_ref.hpp>
#include<string>
#include<sstream>
#include<iostream>
#include<boost/algorithm/string.hpp>
#include<vector>
#include<map>

using namespace std;
using namespace boost;
class string_processor
{
public:
	static inline int locator(string_ref str, int n_th, string_ref strf);
	static inline string extractor(string_ref str, int pos_one, int pos_two);
	static inline string cuttor(string_ref& str, int length, int cut_len = 0);
	class string_protector
	{
	public:
		string_protector(string pro_one, string pro_two);
		string_protector(string pro_same);
		string_protector(pair<string, string> out_pair);
		string_protector(const string_protector&);
		int pro_one();
		int pro_two();
		pair<int, int> pro_pair();
		bool operator ==(pair<int, int> out_pro);
		bool operator !();
		bool operator &(int position);
		bool operator &(pair<int, int> position);
		void feed(string str);
		void left_adjust(int inc_count = 1);
		void right_adjust(int inc_count = 1);
		void move_to_next_protection();
		void reset();
	private:
		int last_one = 0;
		int last_two = 0;
		int current_position = 0;
		int left_adjustion_inc_cnt = 0;
		int right_adjustion_inc_cnt = 0;
		bool protector_end = false;
		string feed_str;
		pair<string, string> protector;
	};
	class symbol_locator 
	{
	public:
		symbol_locator(string symbol, string str);
		pair<int, int> next();
		pair<int, int> last();
		void reset();
		bool operator !();
		string cut();
		void set_cut_off();
	private:
		int last_pos = 0;
		int cut_pos = 0;
		bool m_unavailble = false;
		string_ref m_cut_off_ref;
		string m_symbol;
		string m_str;
		int pos = 0;
	};
	class string_breaker
	{
	public:
		string_breaker(string& str);
		void set_point(pair<int, int> point);
		string str_break();
	private:
		vector<pair<int, int>> points;
		string_ref m_strf;
	};
	class protector_token
	{
	public:
		protector_token(string, string_protector, int len1, int len2);
		bool operator!();
		void set_protector(string, string);
		void set_token_devider(string);
		string take();
		pair<string, string> get_non_concerned();
	private:
		string_protector protector;
		pair<int, int> length;
		string strf;
		string token_divider;
		bool token_end = false;
		pair<string, string> non_concerned;
	};
};

