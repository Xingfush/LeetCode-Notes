
void Reverse(char* begin, char* end)
{
	if (begin == nullptr || end == nullptr)
		return;
	while (begin < end)
	{
		swap(*begin++, *end--);
	}
}

char* ReverseSentence(char* strings)
{
	if (strings == nullptr)
		return nullptr;
	char* start = strings;
	char* end = strings;
	while (*end != '\0')
		end++;
	end--;// 左闭右闭
	Reverse(start, end);
	end = strings;
	while (*start != '\0')
	{
		if (*start == ' ')
			start++, end++;// 用来应对出现两个空格的异常情况
		else if (*end == ' ' || *end == '\0')
		{
			Reverse(start, --end);
			start = ++end; // 同时移动到下一个词的第一位
		}
		else
			end++; // 使用end来定标
	}
	return strings;
}

