using System;
using System.Collections.Generic;
using System.Net.Http;

void DownloadPage(HttpClient session, string URL)
{
    var content = session.GetStringAsync(URL).Result;
    Console.WriteLine($"Read {content.Length} from {URL}");
}

void DownloadAllPages(string[] pages)
{
    var session = new HttpClient();
    foreach (string page in pages)
    {
        DownloadPage(session, page);
    }
}

string[] GetPages()
{
    var pages = new List<string>();
    for (int i = 0; i < 100; ++i)
    {
        pages.Add("https://www.jython.org");
        pages.Add("http://olympus.realpython.org/dice");
    }
    return pages.ToArray();
};


var pages = GetPages();
var startTime = DateTime.Now;
DownloadAllPages(pages);
var endTime = DateTime.Now;
var duration = endTime - startTime;
Console.WriteLine($"Downloaded {pages.Length} in {duration.TotalSeconds} seconds");
