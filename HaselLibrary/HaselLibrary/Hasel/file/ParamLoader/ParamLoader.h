#pragma once

#include<string>
#include<map>

namespace hasel
{
	namespace file
	{
		/// <summary>
		/// テキストファイルからパラメータを取得するクラス
		/// </summary>
		class ParamLoader
		{
		private:
			//パラメータ保存用変数
			std::map<std::string, std::string> params;
			//エラーログ
			mutable std::string errorLog;

		public:
			/// <summary>
			/// コンストラクタ
			/// </summary>
			ParamLoader();

			/// <summary>
			/// テキストファイルからパラメータをロードする
			/// </summary>
			/// <param name="path">ファイルパス</param>
			void Load(const std::string& path);

			/// <summary>
			/// int型としてパラメータを取得する
			/// </summary>
			/// <param name="paramName">パラメータ名</param>
			/// <returns>パラメータ</returns>
			int GetAsInt(const std::string& paramName)const;

			/// <summary>
			/// float型としてパラメータを取得する
			/// </summary>
			/// <param name="paramName">パラメータ名</param>
			/// <returns>パラメータ</returns>
			float GetAsFloat(const std::string& paramName)const;

			/// <summary>
			/// string型としてパラメータを取得する
			/// </summary>
			/// <param name="paramName">パラメータ名</param>
			/// <returns>パラメータ</returns>
			std::string GetAsString(const std::string& paramName)const;

			/// <summary>
			/// エラーログを取得する
			/// </summary>
			/// <returns>エラーログ文字列</returns>
			std::string GetErrorLog()const;
		};
	}
}