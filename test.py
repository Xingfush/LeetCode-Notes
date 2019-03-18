
def getUniqueStrs(strlist):
    result = set()
    for str in strlist:
        if str not in result:
            result.add(str)

    return list(result)

if __name__ == "__main__":
    strs = ["hello","world","allen","hello","world","allen"]
    print(getUniqueStrs(strs))
