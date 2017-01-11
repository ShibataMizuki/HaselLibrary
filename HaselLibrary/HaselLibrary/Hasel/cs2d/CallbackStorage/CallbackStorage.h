#pragma once

#include<map>
#include<list>
#include<functional>

#include"HaselAlias.h"

namespace hasel
{
	namespace cs2d
	{
		class RigidBody;
		class Callback;

		/// <summary>
		/// 衝突コールバック保管クラス
		/// </summary>
		class CallbackStorage
		{
		private:
			std::map<std::pair<int,int>,std::list<Callback>> callbacks;

		public:
			/// <summary>
			/// 衝突ゴールバックを追加する
			/// </summary>
			/// <param name="callback">追加する衝突コールバック</param>
			void AddCallback(const Callback& callback);

			/// <summary>
			/// 衝突コールバックを取り除く
			/// </summary>
			/// <param name="callback">取り除く衝突コールバック</param>
			void RemoveCallback(const Callback& callback);

			/// <summary>
			/// 衝突コールバックリストを取得する
			/// </summary>
			/// <param name="attributeA">属性A</param>
			/// <param name="attributeB">属性B</param>
			/// <returns>衝突コールバックリスト</returns>
			const std::list<Callback>& GetCallbacks(int attributeA, int attributeB)const;

			std::list<Callback> GetAllCallbacks()const;

		};
	}
}